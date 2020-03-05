// Fill out your copyright notice in the Description page of Project Settings.


#include "AudioDeviceInput.h"
//#include "VoiceModule.h"
// Additional includes:
#include "Sound/SoundWaveProcedural.h"
#include "Sound/SoundWave.h"
#include "HAL/Event.h"
#include "Voice.h"
#include "Misc/ConfigCacheIni.h"


void UAudioDeviceInput::SubmitAudioData()
{
	uint32 bytesAvailable = 0;
	EVoiceCaptureState::Type captureState = voiceCapture->GetCaptureState(bytesAvailable);
	if (captureState == EVoiceCaptureState::Ok && bytesAvailable > 0)
	{
		memset(backBuf, 0, 512000);

		uint32 readBytes = 0;
		voiceCapture->GetVoiceData(backBuf, MAX_CAPT_BYTES, readBytes);
		Output->QueueAudio(backBuf, readBytes);
	}
}

void UAudioDeviceInput::AudioCopyThread()
{
	while (true)
	{
		if(bExitCopyThread) break;
		SubmitAudioData();
	}
}

// Called every frame
void UAudioDeviceInput::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

#ifndef MT_AUDIOLOOP
	SubmitAudioData();
#endif
}

void UAudioDeviceInput::InitializeCapture(FString AudioDeviceName /*= TEXT("Default Device")*/, int SampleRate /*= 44100*/)
{
	GConfig->SetBool(TEXT("Voice"), TEXT("bEnabled"), true, GEngineIni);
	
	if (SampleRate == 0)
		SampleRate = UVOIPStatics::GetVoiceSampleRate();
	Output = NewObject<USoundWaveProcedural>();

	Output->SetSampleRate(SampleRate);
	Output->NumChannels = 1;
	Output->Duration = INDEFINITELY_LOOPING_DURATION;
	Output->SoundGroup = SOUNDGROUP_Voice;
	Output->bLooping = false;

	Stop();
	SetSound(Output);
	voiceCapture = FVoiceModule::Get().CreateVoiceCapture(AudioDeviceName, SampleRate);
	voiceCapture->Start();

#ifdef MT_AUDIOLOOP
	copyThread = MakeShared<std::thread>(std::bind(&UAudioDeviceInput::AudioCopyThread, this));
#endif

	Play();
}

bool UAudioDeviceInput::IsCapturing() const
{
	return voiceCapture ? voiceCapture->IsCapturing() : false;
}

void UAudioDeviceInput::PrintHello()
{
	GEngine->AddOnScreenDebugMessage(10, 1.0f, FColor::Cyan, "Hello World");
}

void UAudioDeviceInput::BeginDestroy()
{
	Super::BeginDestroy();

	Stop();
	
	bExitCopyThread = true;

#ifdef MT_AUDIOLOOP
	if(!copyThread) return;
	
	copyThread->join();
	copyThread.Reset();
#endif

}



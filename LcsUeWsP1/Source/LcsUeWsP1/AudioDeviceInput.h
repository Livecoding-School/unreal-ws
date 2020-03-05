// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <thread>

#include "CoreMinimal.h"
#include "Components/AudioComponent.h"

#include "AudioDeviceInput.generated.h"

#define MAX_CAPT_BYTES 512000
#define MT_AUDIOLOOP 1

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LCSUEWSP1_API UAudioDeviceInput : public UAudioComponent
{
	GENERATED_BODY()
	
private:
	
	uint8 backBuf[MAX_CAPT_BYTES];

protected:
	
	TSharedPtr<class IVoiceCapture> voiceCapture;
	TSharedPtr<std::thread> copyThread;

	bool bExitCopyThread = false;

	void SubmitAudioData();

	void AudioCopyThread();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	class USoundWaveProcedural* Output;

	UFUNCTION(BlueprintCallable)
	void InitializeCapture(FString AudioDeviceName = TEXT("Default Device"), int SampleRate = 44100);

	UFUNCTION(BlueprintPure)
	bool IsCapturing() const;
	
	UFUNCTION(BlueprintCallable)
	void PrintHello();

	void BeginDestroy() override;
};

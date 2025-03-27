// Copyright Your Company, All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "BRUIStackManager.h"
#include "BRUISubsystem.generated.h"

UCLASS()
class BRUISYSTEM_API UBRUISubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintCallable, Category = "UI|Subsystem")
    UBRUIStackManager* GetMainStackManager() const { return MainStackManager; }

    UFUNCTION(BlueprintCallable, Category = "UI|Subsystem")
    UBRUIStackManager* GetPopupStackManager() const { return PopupStackManager; }

    UFUNCTION(BlueprintCallable, Category = "UI|Subsystem")
    UBRWidget* CreateBRWidget(TSubclassOf<UBRWidget> WidgetClass);

    UFUNCTION(BlueprintCallable, Category = "UI|Subsystem")
    bool PushMainWidget(UBRWidget* Widget);

    UFUNCTION(BlueprintCallable, Category = "UI|Subsystem")
    UBRWidget* PopMainWidget();

    UFUNCTION(BlueprintCallable, Category = "UI|Subsystem")
    bool PushPopupWidget(UBRWidget* Widget);

    UFUNCTION(BlueprintCallable, Category = "UI|Subsystem")
    UBRWidget* PopPopupWidget();

    UFUNCTION(BlueprintCallable, Category = "UI|Subsystem")
    UBRWidget* CreateAndPushMainWidget(TSubclassOf<UBRWidget> WidgetClass);

    UFUNCTION(BlueprintCallable, Category = "UI|Subsystem")
    UBRWidget* CreateAndPushPopupWidget(TSubclassOf<UBRWidget> WidgetClass);

private:
    UPROPERTY(Transient)
    UBRUIStackManager* MainStackManager;

    UPROPERTY(Transient)
    UBRUIStackManager* PopupStackManager;
};
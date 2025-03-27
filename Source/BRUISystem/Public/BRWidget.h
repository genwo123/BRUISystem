// Copyright Your Company, All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BRWidget.generated.h"

UCLASS(Blueprintable, Abstract)
class BRUISYSTEM_API UBRWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UBRWidget(const FObjectInitializer& ObjectInitializer);

    // Lifecycle methods
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    // Activation methods
    UFUNCTION(BlueprintCallable, Category = "UI|Lifecycle")
    virtual void Activate();

    UFUNCTION(BlueprintCallable, Category = "UI|Lifecycle")
    virtual void Deactivate();

    UFUNCTION(BlueprintPure, Category = "UI|Lifecycle")
    bool IsActive() const { return bIsActive; }

    // Replication support
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    // Interface for derived classes to implement
    UFUNCTION(BlueprintImplementableEvent, Category = "UI|Events")
    void OnWidgetActivated();

    UFUNCTION(BlueprintImplementableEvent, Category = "UI|Events")
    void OnWidgetDeactivated();

    // State
    UPROPERTY(Replicated, BlueprintReadOnly, Category = "UI|State")
    bool bIsActive;
};
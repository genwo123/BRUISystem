#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BRWidget.generated.h"

/**
 * �⺻ ���� Ŭ���� - ��� UI ����� �θ�
 */
UCLASS(Abstract, Blueprintable)
class BRUISYSTEM_API UBRWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UBRWidget(const FObjectInitializer& ObjectInitializer);

    // ���� Ȱ��ȭ/��Ȱ��ȭ �޼���
    UFUNCTION(BlueprintCallable, Category = "BR_UI")
    virtual void Activate();

    UFUNCTION(BlueprintCallable, Category = "BR_UI")
    virtual void Deactivate();

    //// ���� ��� ���
    //UFUNCTION(BlueprintCallable, Category = "BR|UI|Sound")
    //void PlaySound(class USoundBase* Sound);

    // ���� ���� Ȯ��
    UFUNCTION(BlueprintPure, Category = "BR_UI")
    bool IsActive() const { return bIsActive; }

protected:
    // ���� ����
    UPROPERTY(BlueprintReadOnly, Category = "BR_UI")
    bool bIsActive = false;

    // ������ Ȱ��ȭ �� ���� �̺�Ʈ
    UFUNCTION(BlueprintImplementableEvent, Category = "BR_UI")
    void OnActivated();

    // ������ ��Ȱ��ȭ �� ���� �̺�Ʈ
    UFUNCTION(BlueprintImplementableEvent, Category = "BR_UI")
    void OnDeactivated();

    virtual void NativeConstruct() override;
};
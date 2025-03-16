# match3 项目的流程图

#### 流程图的意思


#### 类图的意思
继承 <|--
依赖 <..
关联 <--
聚合 o..
组合 \*--\*

```mermaid
flowchart LR

classDef redNode fill:#D50000,color:#000000;
classDef pinkNode fill:#E1BEE7,color:#000000;
classDef yellowNode fill:#FFF9C4,color:#000000;
classDef blackNode fill:#000000,stroke:#FFD600,stroke-width:4px,stroke-dasharray: 0,color:#FFFFFF;
classDef greenNode fill:#00F840,color:#000000;
classDef reminderNode stroke:#FFD600,stroke-width:4px,stroke-dasharray: 0,fill:#000000,color:#FFFFFF;
classDef blueSubgraph fill:#BBDEFB;
%% Nodes
main("Match3")
level1("Main")
level2("GameLevel")
%% Edge connections between nodes
main -->|level1| level1
main -->|level2| level2

%% Individual node styling. Try the visual editor toolbar for easier styling!


subgraph main_level["Main level 流程图"]
    platform(获取平台)
    is_touch_device(是否为触摸设备)
    show_widget(显示界面)
    main_level_start(开始)
    main_level_start -->  platform 
    main_level_start --> is_touch_device
    platform --> show_widget
    is_touch_device --> show_widget


    
end

subgraph widget_blueprint[控件蓝图]
  title_screen(TitleScreen)
  main_menu(MainMenu)

  title_screen <-->  main_menu
end
```  


```mermaid   
classDiagram
USaveGame <|-- UMatch3SaveGame
class UMatch3SaveGame {
  # TMap<FString, int32> Match3CustomIntData
  + TMap<FString, FMatch3LevelSaveData> Match3SaveData
  + LoadCustomInt(FString FieldName, int32& Value) bool
  + SaveCustomInt(FString FieldName, int32 Value) void
  + ClearCustomInt(FString FieldName) void 
} 
note for UMatch3SaveGame  "
@see UGameplayStatics::CreateSaveGameObject
@see UGameplayStatics::SaveGameToSlot
@see UGameplayStatics::DoesSaveGameExist
@see UGameplayStatics::LoadGameFromSlot
@see UGameplayStatics::DeleteGameInSlot
"
UGameInstance <|-- UMatch3GameInstance
class UMatch3GameInstance {
  - FDelegateHandle LoginChangedHandle
  - FDelegateHandle EnteringForegroundHandle
  - FDelegateHandle EnteringBackgroundHandle
  - FDelegateHandle ViewportHandle
  - FDelegateHandle UnexpectedPurchaseHandle
  # FString SaveGamePrefix
  # FString DefaultSaveGameSlot
  + UMatch3SaveGame* InstanceGameData

  # GetSaveSlotName() FString
  + Init() void
  + Shutdown() void
  + InitSaveGameSlot() void
  + FindSaveDataForLevel(UObject* WorldContextObject, FMatch3LevelSaveData& OutSaveData) bool  
  + SaveGame() void
  + LoadCustomInt(FString FieldName, int32& Value) bool 
  + SaveCustomInt(FString FieldName, int32 Value) void   
  + ClearCustomInt(FString FieldName) void 
  + UpdateSave(UObject* WorldContextObject, FMatch3LevelSaveData& NewData) void
  + UpdateUIAfterSave() void
  + RegisterOnlineID(FString NewOnlineID) void
  + OnLoginChanged(bool bLoggingIn, int32 UserID, int32 UserIndex) void
  + OnEnteringForeground() void
  + OnEnteringBackground() void
  + OnViewportResize_Internal(FViewport* Viewport, uint32 ID) void
  + OnViewportResize() void
  + OnUnexpectedPurchase_Internal(const FUniqueNetId& UserId) void
  + OnUnexpectedPurchase() void
}

UMatch3GameInstance <|-- GlobalGameInstance
note for GlobalGameInstance "蓝图类"


APlayerController <|-- AMatch3PlayerController
class AMatch3PlayerController {
  # int32 Score
  # float DisplayedScore
  # float ScoreChangeRate
  # FTimerHandle TickScoreDisplayHandle

  + int32 ComboPower
  + int32 MaxComboPower
  + AddScore(int32 Points, bool bForceImmediateUpdate = false) void
  + GetScore() int32
  + GetDisplayedScore() int32
  + CalculateBombPower() int32
  + virtual CalculateBombPower_Implementation() int32

}

AMatch3PlayerController <|-- Match3PC
note for Match3PC "蓝图类"

```

## 蓝图方法

Get Platform Name: 获取平台名字
  - Windows
  - iOS
  - Android


## widget 控件

每个控件蓝图，有个属性 details , 在 Graph 页签里。
其中可以选择背景图

## 
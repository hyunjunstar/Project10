# 언리얼 모듈 플러그인 생성 과정 및 오류 해결

## Test 모듈

먼저 Source/Test 폴더를 만들고 기본 파일을 추가했다.

```text
Source/Test/
  Test.Build.cs
  Test.h
  Test.cpp
```

Test.Build.cs에는 기본으로 필요한 모듈을 넣었다.

```csharp
PublicDependencyModuleNames.AddRange(new string[]
{
	"Core",
	"CoreUObject",
	"Engine"
});
```

Test.cpp에서는 일반 모듈이라 아래처럼 등록했다.

```cpp
IMPLEMENT_MODULE(FDefaultModuleImpl, Test);
```

그 다음 Project10.Target.cs, Project10Editor.Target.cs에 Test를 추가했다.

```csharp
ExtraModuleNames.AddRange(new string[] { "Project10", "Test" });
```

Project10.uproject에도 Test 모듈을 추가했다.

```json
{
	"Name": "Test",
	"Type": "Runtime",
	"LoadingPhase": "PreDefault"
}
```

## TestActor

Test 모듈 안에 ATestActor를 만들었다.

```text
Source/Test/TestActor.h
Source/Test/TestActor.cpp
```

BeginPlay에서 로그와 화면 메시지를 출력하게 했다.

```cpp
UE_LOG(LogTemp, Warning, TEXT("TestActor"));
```

화면 메시지는 GEngine->AddOnScreenDebugMessage로 확인했다.

그 다음 메인 모듈의 캐릭터에서 TestActor를 쓰기 위해 Project10.Build.cs에 Test를 추가했다.

```csharp
PrivateDependencyModuleNames.AddRange(new string[] { "Test" });
```

캐릭터 cpp에서 TestActor.h를 include하고 SpawnActor로 생성했다.

```cpp
World->SpawnActor<ATestActor>(
	ATestActor::StaticClass(),
	SpawnLocation,
	SpawnRotation
);
```

실행했을 때 World Outliner에 TestActor가 생기는 것과 화면 메시지가 뜨는 것을 확인했다.

## Temporary 플러그인

이번에는 프로젝트 모듈이 아니라 플러그인을 만들었다.

```text
Plugins/Temporary/
  Content/
  Source/Temporary/
  Temporary.uplugin
```

Temporary.uplugin에는 플러그인 정보를 넣었다.

```json
{
	"FileVersion": 3,
	"Version": 1,
	"VersionName": "1.0",
	"FriendlyName": "Temporary",
	"Description": "Temporary plugin for module and plugin practice.",
	"Category": "Project",
	"CanContainContent": true,
	"IsBetaVersion": false,
	"Installed": false,
	"Modules": [
		{
			"Name": "Temporary",
			"Type": "Runtime",
			"LoadingPhase": "Default"
		}
	]
}
```

플러그인 모듈 쪽에는 StartupModule과 ShutdownModule을 만들었다.

```cpp
void FTemporaryModule::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("Temporary plugin StartupModule"));
}

void FTemporaryModule::ShutdownModule()
{
	UE_LOG(LogTemp, Warning, TEXT("Temporary plugin ShutdownModule"));
}

IMPLEMENT_MODULE(FTemporaryModule, Temporary)
```

마지막으로 Project10.uproject의 Plugins 목록에 Temporary를 추가했다.

```json
{
	"Name": "Temporary",
	"Enabled": true
}
```

## 하면서 막혔던 부분

### uproject에 주석을 넣으면 안 됐다

처음에 uproject 안에 설명을 쓰려고 주석을 넣었는데, uproject는 JSON이라 주석을 쓰면 안 됐다.

### Temporary.uplugin이 비어 있으면 안 됐다

처음에 Temporary.uplugin 파일만 만들고 내용을 안 넣었더니 플러그인 정보가 제대로 안 잡혔다. uplugin에는 플러그인 이름, 모듈 이름, CanContainContent 같은 내용을 꼭 넣어야 했다.

### 플러그인 이름을 맞춰야 했다

Temporary.Build.cs, Temporary.cpp, Temporary.uplugin 안의 모듈 이름이 전부 Temporary로 맞아야 했다. 중간에 Test에서 복사한 내용이 남아 있으면 빌드가 안 될 수 있다.

### 플러그인 폴더가 콘텐츠 브라우저에 안 보였다

빌드는 됐는데 콘텐츠 브라우저에서 플러그인 폴더가 안 보여서 헷갈렸다. 콘텐츠 브라우저 설정에서 아래 옵션을 켜야 보였다.

```text
Show Plugin Content
Show C++ Classes
```

### Visual Studio에 새 파일이 안 보였다

플러그인에 새 C++ 파일을 만들었는데 Visual Studio에 바로 안 보였다. Project10.uproject 우클릭 후 Generate Visual Studio project files를 다시 실행하니까 갱신됐다.

### TestActor가 생성됐는데 화면에는 안 보였다

World Outliner에는 TestActor가 생겼는데 뷰포트에서는 안 보였다. Static Mesh 같은 보이는 컴포넌트가 없어서 그런 거였다. 그래서 위치는 Outliner에서 선택하고 Details의 Transform 값으로 확인했다.

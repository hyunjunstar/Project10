// Temporary.cpp

#include "Temporary.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FTemporaryModule"

void FTemporaryModule::StartupModule()
{
    UE_LOG(LogTemp, Warning, TEXT("Temporary plugin StartupModule"));
}

void FTemporaryModule::ShutdownModule()
{
    UE_LOG(LogTemp, Warning, TEXT("Temporary plugin ShutdownModule"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FTemporaryModule, Temporary)
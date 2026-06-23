// Temporary.cpp

#include "Temporary.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_MODULE(FTemporaryModule, Temporary)

void FTemporaryModule::StartupModule()
{
    UE_LOG(LogTemp, Warning, TEXT("Temporary plugin StartupModule"));
}

void FTemporaryModule::ShutdownModule()
{
    UE_LOG(LogTemp, Warning, TEXT("Temporary plugin ShutdownModule"));
}



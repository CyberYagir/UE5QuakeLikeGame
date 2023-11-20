using UnrealBuildTool;
using System.Collections.Generic;

public class ShooterRoomsServerTarget : TargetRules //Change this line according to the name of your project
{
    public ShooterRoomsServerTarget(TargetInfo Target) : base(Target) //Change this line according to the name of your project
    {
        Type = TargetType.Server;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.Add("ShooterRooms"); //Change this line according to the name of your project
    }
}
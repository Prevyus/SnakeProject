#pragma once

#define debug(msg) UE_LOG(LogTemp, Warning, TEXT(msg))

#define DEBUG_ROTATOR(rot) UE_LOG(LogTemp, Warning, TEXT(#rot ": Pitch=%f, Yaw=%f, Roll=%f"), rot.Pitch, rot.Yaw, rot.Roll)

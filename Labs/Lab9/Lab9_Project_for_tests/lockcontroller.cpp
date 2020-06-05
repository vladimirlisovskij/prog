#include "lockcontroller.h"

LockController::LockController(IKeypad* keypad, ILatch* latch)
    :keypad(keypad), latch(latch), password("0000")
{
}

void LockController::resetPassword()
{
    if (!isCorrectPassword()) return;

    PasswordResponse other = keypad->requestPassword();
    if (other.status != PasswordResponse::Status::OK) return;
    password = other.password;
}

bool LockController::isCorrectPassword()
{
    PasswordResponse old = keypad->requestPassword();
    if (old.status != PasswordResponse::Status::OK) return false;
    if (old.password != password) return false;
    return true;
}

HardWareStatus LockController::hardWareCheck()
{
    if(keypad == nullptr || latch == nullptr || !keypad->isActive() || !latch->isActive())
        return HardWareStatus::ERROR;
    return HardWareStatus::OK;
}

bool LockController::isDoorOpen()
{
    if(latch->getDoorStatus() == DoorStatus::OPEN) return true;
    return false;
}

DoorStatus LockController::unlockDoor()
{
    return latch->open();
}

DoorStatus LockController::lockDoor()
{
    return latch->open();
}

void LockController::wait()
{
    keypad->wait();
}

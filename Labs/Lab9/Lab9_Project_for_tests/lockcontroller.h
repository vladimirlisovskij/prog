/****************************************************************************************************
* Возможное использование класса
*
* ConcretKeypad kpd;                                     // Конкретная реализация интерфейса IKeypad
* ConcretILatch lth;                                     // Конкретная реализация интерфейса ILatch
* LockController lc(&kpd, &lth);
* if (lc.hardWareCheck() != HardWareStatus::OK) return;  // Проверяем работу железа
* lc.resetPassword();                                    // Меняем дефолтный пароль
*
* while(true){                                           // Рабочий цикл
*     lc.wait();                                         // Из метода не выйдем, пока юзер не коснётся экрана
*     if (lc.isDoorOpen()) lc.lockDoor();                // Если дверь была открыта - закрываем
*     else if(lc.isCorrectPassword()) lc.unlockDoor();   // Если закрыта, просим пароль и открываем, если он верный
* }
*****************************************************************************************************/

#ifndef LOCKCONTROLLER_H
#define LOCKCONTROLLER_H
#include "IKeypad.h"
#include "ILatch.h"
#include <string>

enum class HardWareStatus {
    OK,    // Оборудование в порядке
    ERROR  // Оборудование не в порядке
};


/**
 * @brief The LockController class
 *
 * Класс управления кодовым электронным дверным замком.
 * Для работы необходим котроллер клавиатуры и контроллер защёлки (реализовывать не нужно).
 */
class LockController
{
public:
    LockController(IKeypad* keypad, ILatch* latch);
    // Изменение пароля на новый (нужно знать старый)
    void resetPassword();
    // Спрашивает у пользователя пароль и сравнивает с уже заданным
    bool isCorrectPassword();
    // Проверяет состояние контроллеров клавиатуры и защёлки
    HardWareStatus hardWareCheck();
    // Состояние защёлки двери
    bool isDoorOpen();
    // Задвинуть язычок защёлки
    DoorStatus unlockDoor();
    // Выдвинуть язычок защёлки
    DoorStatus lockDoor();
    // Спать, пока нет новых команд от пользователя
    void wait();
private:
    IKeypad* keypad;
    ILatch* latch;
    std::string password;
};

#endif // LOCKCONTROLLER_H

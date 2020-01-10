МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>
### Отчёт по лабораторной работе № 3<br/> по дисциплине "Программирование"
<br/>
​
студента 1 курса группы 191(2)  
<br/>Лисовского Владимира Сергеевича  
<br/>направления подготовки 09.03.01 "Информатика и вычислительная техника" 

<br/><br/>
<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>
​
Симферополь, 2019

#### Цель

* Закрепить навыки разработки программ использующих операторы цикла;
* Закрепить навыки разработки программ использующих массивы;
* Освоить методы подключения библиотек.

#### Ход работы

1. Исходное изображение

    ![](pic3.bmp)
2. Ключ

    00r 00g 00b 01r 01g 01b 10r 10g
3. Код программы

    ```cpp
    //
    // Created by canned_dead on 12.12.2019.
    //
    #include <iostream>
    #include <ostream>
    #include <cmath>
    
    #include "libbmp.h"
    
    enum canal{
        RED,
        GREEN,
        BLUE
    };
    
    char to_char(bool arr [8]){
        int sum = 0;
        for (int i = 0; i < 8; i ++){
            sum += std::pow(2, i) * arr[i];
        }
        char res = sum;
        return res;
    }
    
    bool get_bit (int x, int y, BmpImg img){
        static int len = 0;
        int color_num;
        static canal color = RED;
        static bool temp [8] = {};
    
        switch (color){
            case RED:
                color_num = int(img.red_at(x,y))%2;
                break;
            case GREEN:
                color_num = int(img.green_at(x,y))%2;
                break;
            case BLUE:
                color_num = int(img.blue_at(x,y))%2;
                break;
        }
        temp[7 - len] = color_num;
        len ++;
    
        if (len == 8){
            char temp_char = to_char(temp);
            if (temp_char == char(0)){
                std::cout << std::endl;
                len = 0;
                color = static_cast<canal> ((color + 1)%3);
                return false;
            }else{
                std::cout << temp_char;
                len = 0;
                color = static_cast<canal> ((color + 1)%3);
                return true;
            }
        }
        color = static_cast<canal> ((color + 1)%3);
        return true;
    }
    
   int main() {
       BmpImg img; img.read ("pic3.bmp");
   
       const int x_max = 600, y_max = 650;
       for (int x_pos = 0; x_pos < x_max; x_pos ++){
           for (int y_pos = 0; y_pos < y_max; y_pos ++){
               if (!get_bit(x_pos, y_pos, img)) return 0;
               if (!get_bit(x_pos, y_pos, img)) return 0;
               if (!get_bit(x_pos, y_pos, img)) return 0;
           }
       }
       return 0;
   }
    ```
4. Декодированное сообщение

    Thomas Jefferson (April 13, 1743[a] � July 4, 1826) was an American statesman, diplomat, lawyer, architect, philosopher, and Founding Father who served as the third president of the United States from 1801 to 1809. Previously, he had served as the second vice president of the United States from 1797 to 1801. The principal author of the Declaration of Independence, Jefferson was a proponent of democracy, republicanism, and individual rights, motivating American colonists to break from the Kingdom of Great Britain and form a new nation; he produced formative documents and decisions at both the state and national level.
    During the American Revolution, he represented Virginia in the Continental Congress that adopted the Declaration, drafted the law for religious freedom as a Virginia legislator, and served as the second Governor of Virginia from 1779 to 1781, during the American Revolutionary War. He became the United States Minister to France in May 1785, and subsequently the nation's first secretary of state under President George Washington from 1790 to 1793. Jefferson and James Madison organized the Democratic-Republican Party to oppose the Federalist Party during the formation of the First Party System. With Madison, he anonymously wrote the controversial Kentucky and Virginia Resolutions in 1798 and 1799, which sought to strengthen states' rights by nullifying the federal Alien and Sedition Acts.
    As president, Jefferson pursued the nation's shipping and trade interests against Barbary pirates and aggressive British trade policies. He also organized the Louisiana Purchase, almost doubling the country's territory. As a result of peace negotiations with France, his administration reduced military forces. He was reelected in 1804. Jefferson's second term was beset with difficulties at home, including the trial of former vice president Aaron Burr. American foreign trade was diminished when Jefferson implemented the Embargo Act of 1807, responding to British threats to U.S. shipping. In 1803, Jefferson began a controversial process of Indian tribe removal to the newly organized Louisiana Territory, and he signed the Act Prohibiting Importation of Slaves in 1807. After retiring from public office, Jefferson founded the University of Virginia.
    Jefferson, while primarily a planter, lawyer and politician, mastered many disciplines, which ranged from surveying and mathematics to horticulture and mechanics. He was an architect in the classical tradition. Jefferson's keen interest in religion and philosophy led to his presidency of the American Philosophical Society; he shunned organized religion but was influenced by both Christianity and deism. A philologist, Jefferson knew several languages. He was a prolific letter writer and corresponded with many prominent people. His only full-length book is Notes on the State of Virginia (1785), considered perhaps the most important American book published before 1800.[1]
    Although regarded as a leading spokesman for democracy and republicanism in the era of the Enlightenment, some modern scholarship has been critical of Jefferson's private life, finding a contradiction between his ownership of the large numbers of slaves that worked his plantations and his famous declaration that "all men are created equal". Although the matter remains a subject of debate, most historians believe that Jefferson had a sexual relationship with his slave Sally Hemings, a mixed-race woman who was a half-sister to his late wife, and that he fathered at least one of her children. Presidential scholars and historians generally praise Jefferson's public achievements, including his advocacy of religious freedom and tolerance in Virginia. Jefferson continues to rank highly among U.S. presidents.

   
#### Ввывод

в ходе лабораторной работы были получены такие навыки, как
* работать с изображениями формата BMP;
* писать сложные функции с использованием статических переменных и перечислений;
* умение создавать многофайловые проекты.


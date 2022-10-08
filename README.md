# Task 1
Зная основые работы операции в двоичной системе счисления, можно воспользоваться знанием того, что четные числа в двоичном коде всегда оканчиваются на 0, тогда
легко можно привести несколько примеров проверки четности числа. 
1. Использование AND оператора.
```C++
bool isEven(int n)
{
    return (!(n & 1));
}
```
2. Использование XOR оператора. 
```C++
bool isEven(int n)
{
    return ((n | 1) > n);
}
```
3. Использование OR оператора.
```C++
bool isEven(int n)
{
    return (n ^ 1 == n + 1);
}
```
4. Функция из задания.
```C++ 
bool isEven(int value)
{
    return value%2==0;
}
```
Проведем дизассемблинг gcc 12.2
![image](https://user-images.githubusercontent.com/55399599/194369449-4229ed4e-1c69-499e-9c49-8865085711de.png)

Проведем дизассемблинг clang 15.0.0
![image](https://user-images.githubusercontent.com/55399599/194623351-67430be7-0528-44d6-9921-3dac1206d20d.png)

Как видим, для gcc в предлагаемой заданием функцией также используется оператор AND как и в первой моей реализации четности.
Clang же не делает оптимизацию, и используется операция деления для функции %2.
Вероятно компиляторы для языков, где эти выражения эквивалентны, будут одинаково реализовывать оба варианта.
Проведем бенчмарк, подав на вход каждой функции числа от 0 до 2000000000, используем компилятор clang

The time for %2: 6.562500 seconds \
The time for XOR: 4.546875 seconds \
The time for OR: 4.218750 seconds \
The time for AND: 4.078125 seconds 

Как мы видим, худший результат выдает %2 ввиду операции деления, остальные функции показывают неплохое время, AND - лучшее
Проведем бенчмарк, используя другой компилятор gcc(g++ 12.2)

The time for %2: 3.843750 seconds \
The time for XOR: 3.984375 seconds \
The time for OR: 4.093750 seconds \
The time for AND: 3.812500 seconds 

Как мы видим, ввиду того, что реализация для %2 и AND одинакова, то и затраченное время примерно одинаково, также для AND опять лучшая скорость

Однако это еще не все, не стоит забывать про флаги оптимизации, для более удобного бенчмарка воспользуюсь сайтом 
https://quick-bench.com/

Результаты тестов функции от 0 до 2000000000 (пришлось увеличить количество подоваемых чисел дабы результат тестирования был более нагляден)
![image](https://user-images.githubusercontent.com/55399599/194637362-00451409-27d4-4dac-b644-a6819cb12510.png) \
![image](https://user-images.githubusercontent.com/55399599/194637637-15aaaa19-0e8f-4f4f-94aa-124d4760f33b.png) \
Как видим, результы совсем другие, взависимости от используемого уровня оптимизации мы получаем разные лучшие по скорости функции





# Task 2
Первая реализация кругового буфера реализована с помощью массива и указателей, в классе реализована функция для динамического расширения, однако достаточно убрать
проверку на заполнения массива и буфер будет перезаписывающимся или также возможно установить ограничение на запись при заполнении, тогда буфер станет фиксированным

https://github.com/OlegMatveevS/Task/blob/main/TaskTwo/RingBuffer.cpp

Вторая реализация выполнена на списках, 
Циклический связанный список имеет то же преимущество перед кольцевым буфером, что и связный список перед фиксированным массивом. 
Он может различаться по размеру, и вы можете вставлять и элементы без перетасовки.
Из недостатков: нет доступа к массиву O (1) и увеличивается объем работы, если вы расширяете или сжимаете список.

https://github.com/OlegMatveevS/Task/blob/main/TaskTwo/RingBufferList.cpp

Фиксированный кольцевой буфер обычно используется при известном количестве элементов
буфер на списках более гибок в доступе и размещении элементов.

# Task 3
Ввиду того, что для разных случайных значений, разные алгоритмы сортировки будут выдавать разные результаты предложить самый быстрый алгоритм невозможно. \
Взятые мною бенчмарки алгоритмов из свободного доступа \
 Полностью неотсортированный массив: \
![image](https://user-images.githubusercontent.com/55399599/194715961-a265b3df-237b-48e6-87b4-1cb76118a1e3.png) 

 Частично отсортированный массив (половина элементов упорядочена): \
![image](https://user-images.githubusercontent.com/55399599/194715967-e8340721-695f-4ee2-bb1e-437b950b4854.png) 

У разных алгоритмов время работы находится в экспоненциальной или логарифмической зависимости от числа элементов структуры данных (массива) N.
Как мы видим, ни один из алгоритмов не является лидером во всех тестах, например в частично отсортированном массиве quick sort для небольших массивов данных
показывает худший результат, однако при увеличении числа элементов разрыв сокращается, и quick sort становится лидером



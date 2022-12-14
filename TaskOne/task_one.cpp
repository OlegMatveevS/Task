// Если установлен последний бит, то число нечетное, иначе четное.
// побитовое И числа на 1 будет равна 1, если оно нечетное, потому что последний бит уже будет установлен.
// В противном случае он выдаст 0 в качестве вывода.
bool isEven(int n)
{
    return (!(n & 1));
}

// Если установлен последний бит, то число нечетное, иначе четное.
// побитовая операция ИЛИ числа на 1 увеличивает значение числа на 1, если число четное,
// иначе оно останется неизменным. Итак, если после операции ИЛИ над числом с 1 результат будет больше числа,
// то оно четное и мы вернем true, иначе нечетное и вернем false.
bool isEven(int n)
{
    return ((n | 1) > n);
}

//Если установлен последний бит, то число нечетное, иначе четное.
//побитовая операция XOR числа на 1 увеличивает значение числа на 1, если число четное,
//в противном случае оно уменьшает значение числа на 1, если значение нечетное.
bool isEven(int n)
{
    return (n ^ 1 == n + 1);
}
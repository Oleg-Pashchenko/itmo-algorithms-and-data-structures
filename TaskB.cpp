//
// Created by Oleg Pashchenko on 11.03.2023.
//
#include <iostream>
#include <stack>

int main() {
    std::string s; std::cin >> s; // объявляем строку и считываем её
    std::stack<char> d; // создаём стек для символов
    int i[s.size()/2], c=0; // создаём массив и счётчик для животных и ловушек
    std::stack<int> a, t; // создаём стеки для id животных и ловушек
    for (int j=0; j<s.size(); j++){ // проходим по всей строке
        if (islower(s[j])) a.push(++c); // если символ - животное, добавляем его id в стек животных
        else t.push(j-c); // если символ - ловушка, добавляем расстояние до последнего животного в стек ловушек
        if (d.empty() || s[j]==d.top()) d.push(s[j]); // если стек символов пуст или текущий символ совпадает с последним символом в стеке, добавляем его в стек
        else if (tolower(s[j])==tolower(d.top())){ // если текущий символ является парой последнему символу в стеке
            i[t.top()]=a.top(); // добавляем id животного в соответствующую ловушку
            t.pop(); a.pop(); d.pop(); // удаляем обработанные элементы из стеков
        } else d.push(s[j]); // иначе добавляем текущий символ в стек
    }
    if (d.empty()){ // если стек символов пуст
        std::cout<<"Possible\n"; // выводим "Possible"
        for(int x: i) std::cout<<x<<" "; // выводим id животных для каждой ловушки
        std::cout<<"\n"; // переходим на новую строку
    } else std::cout<<"Impossible\n"; // если стек символов не пуст, выводим "Impossible"
    return 0; // возвращаем 0, чтобы завершить программу
}
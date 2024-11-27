#include "modGronsfeld.h"
#include <iostream>
/*!
* \brief Основная функция программы.
*
* Запускает программу шифрования и расшифровки текста с использованием
шифра Гронсфельда.
* Пользователь может шифровать и расшифровывать текст с заданным ключом.
*
* \return Возвращает 0 в случае успешного завершения программы.
*/
int main() {
try {
std::locale loc("ru_RU.UTF-8");
std::locale::global(loc);
std::wstring key, text;
int op;
std::wcout << L"Введите ключ для шифра Гронсвельда: ";
std::wcin >> key;
modAlphaCipher cipher(key);
do {
std::wcout << L"Выберите операцию (0 - выход, 1 - зашифровать,
2 - расшифровать): ";
std::wcin >> op;
if (op > 2) {
std::wcout << L"Некорректная операция\n";
} else if (op > 0) {
std::wcout << L"Введите текст: ";
std::wcin >> text;
if (isValid(text)) {
if (op == 1) {
std::wcout << L"Зашифрованный текст: " <<
cipher.encrypt(text) << std::endl;
} else {
std::wcout << L"Расшифрованный текст: " <<
cipher.decrypt(text) << std::endl;
}
} else {
std::wcout << L"Некорректный текст для
шифрования/расшифрования\n";
}
}
} while (op != 0);
} catch (const std::exception& e) {
std::wcerr << L"Ошибка: " << e.what() << std::endl;
}
return 0;
}

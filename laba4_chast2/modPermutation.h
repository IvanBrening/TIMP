#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <locale>
#include <map>
#include <algorithm>
#include <iostream>
/*!
* \class modPermutationCipher
* \brief Класс для шифрования и расшифровки текста с использованием шифра
перестановки.
*
* Этот класс реализует шифрование и расшифровку текста на основе шифра
перестановки. Ключ для шифрования должен быть положительным
* целым числом, и алфавит поддерживает как русские, так и английские
буквы.
*/
class modPermutationCipher {
private:
std::wstring alphabet; ///< Алфавит для шифрования/расшифровки.
std::vector<int> key; ///< Ключ для шифрования, представленный
вектором целых чисел.
public:
/*!
* \brief Конструктор для инициализации объекта с ключом.
*
* Конструктор принимает ключ в виде строки и преобразует его в вектор
чисел для дальнейшего использования
* при шифровании и расшифровке текста.
*
* \param skey Строка, представляющая ключ.
* \throws std::invalid_argument Если ключ некорректен.
*/
modPermutationCipher(const std::wstring& skey);
/*!
* \brief Шифрование текста.
*
* Функция шифрует текст на основе ключа.
*
* \param open_text Строка с открытым текстом.
* \return Зашифрованный текст.
* \throws std::invalid_argument Если текст некорректен.
*/
std::wstring encrypt(const std::wstring& open_text);
/*!
* \brief Расшифровка текста.
*
* Функция расшифровывает текст на основе ключа.
*
* \param cipher_text Строка с зашифрованным текстом.
* \return Расшифрованный текст.
* \throws std::invalid_argument Если текст некорректен.
*/
std::wstring decrypt(const std::wstring& cipher_text);
/*!
* \brief Валидация ключа.
*
* Функция проверяет, что ключ состоит только из цифр и является
положительным числом.
*
* \param key Строка с ключом.
* \throws std::invalid_argument Если ключ некорректен.
*/
void validateKey(const std::wstring& key);
/*!
* \brief Валидация текста.
*
* Функция проверяет, что текст состоит только из допустимых символов
алфавита и не является пустым.
*
* \param text Строка с текстом.
* \throws std::invalid_argument Если текст некорректен.
*/
void validateText(const std::wstring& text);
};

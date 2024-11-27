#pragma once
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>
/*!
* \class modAlphaCipher
* \brief Класс для шифрования и расшифровки текста с использованием шифра
Гронсфельда.
*
* Этот класс реализует шифрование и расшифровку текста на основе шифра
Гронсфельда. Алгоритм использует ключ, который состоит из числовых
значений,
* соответствующих символам русского алфавита. Операции шифрования и
расшифровки выполняются по модулю количества букв в алфавите.
*/
class modAlphaCipher {
private:
std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///<
Алфавит
std::map<wchar_t, int> alphaNum; ///< Карта символов и их индексов
std::vector<int> key; ///< Ключ в виде числового вектора
/*!
* \brief Преобразует строку в вектор чисел.
* \param s Строка для преобразования.
* \return Вектор целых чисел.
* \throws std::invalid_argument Если строка содержит недопустимые
символы.
*/
std::vector<int> convert(const std::wstring& s);
/*!
* \brief Преобразует числовой вектор в строку.
* \param v Вектор чисел.
* \return Строка символов.
* \throws std::invalid_argument Если индекс выходит за пределы
алфавита.
*/
std::wstring convert(const std::vector<int>& v);
public:
modAlphaCipher() = delete; ///< Запрещен конструктор по умолчанию
modAlphaCipher(const std::wstring& skey); ///< Конструктор с ключом
/*!
* \brief Шифрует текст с использованием шифра Гронсфельда.
* \param open_text Текст для шифрования.
* \return Зашифрованный текст.
* \throws std::invalid_argument Если текст пустой или содержит
недопустимые символы.
*/
std::wstring encrypt(const std::wstring& open_text);
/*!
* \brief Расшифровывает текст с использованием шифра Гронсфельда.
* \param cipher_text Текст для расшифровки.
* \return Расшифрованный текст.
* \throws std::invalid_argument Если текст пустой или содержит
недопустимые символы.
*/
std::wstring decrypt(const std::wstring& cipher_text);
};

/**
 * @file modGronsfeld.h
 * @brief Заголовочный файл для реализации шифра Гронсвельда.
 * @details Класс modAlphaCipher предоставляет методы шифрования и расшифрования текста
 * с использованием шифра Гронсвельда. Поддерживаются только заглавные буквы русского алфавита.
 * @author Бренинг И. А.
 */

#pragma once
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>

/**
 * @class modAlphaCipher
 * @brief Реализация шифра Гронсвельда.
 * @details Шифр Гронсвельда использует числовой ключ для шифрования текста.
 */
class modAlphaCipher {
private:
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///< Алфавит
    std::map<wchar_t, int> alphaNum; ///< Карта символов и их индексов
    std::vector<int> key; ///< Ключ в виде числового вектора

    /**
     * @brief Преобразует строку в числовой вектор.
     * @param s Строка для преобразования.
     * @return Числовой вектор.
     * @throws std::invalid_argument Если строка содержит недопустимые символы.
     */
    std::vector<int> convert(const std::wstring& s);

    /**
     * @brief Преобразует числовой вектор в строку.
     * @param v Числовой вектор.
     * @return Преобразованная строка.
     * @throws std::invalid_argument Если индекс вектора выходит за границы алфавита.
     */
    std::wstring convert(const std::vector<int>& v);

public:
    /**
     * @brief Удалённый конструктор по умолчанию.
     */
    modAlphaCipher() = delete;

    /**
     * @brief Конструктор с инициализацией ключа.
     * @param skey Строковый ключ для шифра.
     * @throws std::invalid_argument Если ключ пустой или содержит недопустимые символы.
     */
    modAlphaCipher(const std::wstring& skey);

    /**
     * @brief Шифрует текст.
     * @param open_text Текст для шифрования.
     * @return Зашифрованный текст.
     * @throws std::invalid_argument Если текст пустой или содержит недопустимые символы.
     */
    std::wstring encrypt(const std::wstring& open_text);

    /**
     * @brief Расшифровывает текст.
     * @param cipher_text Текст для расшифрования.
     * @return Расшифрованный текст.
     * @throws std::invalid_argument Если текст пустой или содержит недопустимые символы.
     */
    std::wstring decrypt(const std::wstring& cipher_text);
};

#include <UnitTest++/UnitTest++.h>
#include "modPermutation.h"

// Тест на шифрование пустого текста
TEST(TestEncryptEmptyText) {
    modPermutationCipher cipher(L"123"); // Пример ключа
    CHECK_THROW(cipher.encrypt(L""), std::invalid_argument); // Ожидаем исключение
}

// Тест на дешифрование пустого текста
TEST(TestDecryptEmptyText) {
    modPermutationCipher cipher(L"123"); // Пример ключа
    CHECK_THROW(cipher.decrypt(L""), std::invalid_argument); // Ожидаем исключение
}

// Тест на шифрование текста с невалидным символом
TEST(TestForeignCharacterInText) {
    modPermutationCipher cipher(L"123"); // Пример ключа
    CHECK_THROW(cipher.encrypt(L"Hello"), std::invalid_argument); // Ожидаем исключение
}

// Тест на правильность шифрования
TEST(TestEncryptionCorrectness) {
    modPermutationCipher cipher(L"123"); // Пример ключа
    std::wstring encrypted = cipher.encrypt(L"БГЕЖ"); // Здесь проверьте ожидаемый результат
    CHECK(encrypted == L"ВЕЗЗ"); // Ожидаемый результат должен быть проверен
}

// Тест на правильность дешифрования
TEST(TestDecryptionCorrectness) {
    modPermutationCipher cipher(L"123"); // Пример ключа
    std::wstring decrypted = cipher.decrypt(L"ВЕЗЗ"); // Здесь проверьте ожидаемый результат
    CHECK(decrypted == L"БГЕЖ"); // Ожидаемый результат должен быть проверен
}

// Тест на шифрование текста с невалидным ключом
TEST(TestInvalidKey) {
    CHECK_THROW(modPermutationCipher cipher(L"abc"), std::invalid_argument); // Ожидаем исключение
}

// Тест на шифрование текста с нулевым ключом
TEST(TestZeroKey) {
    CHECK_THROW(modPermutationCipher cipher(L"0"), std::invalid_argument); // Ожидаем исключение
}

// Основная функция для запуска тестов
int main() {
    return UnitTest::RunAllTests();
}


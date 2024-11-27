#include "modPermutation.h"
#include <stdexcept>
#include <locale>
/*!
* \brief Конструктор, инициализирующий ключ.
*
* Этот конструктор принимает строку с ключом для шифрования. Ключ должен
быть положительным целым числом.
* Ключ используется для создания вектора чисел, которые будут применяться
при шифровании.
*
* \param skey Строка, представляющая ключ.
* \throws std::invalid_argument Если ключ пустой или не является
положительным числом.
*/
modPermutationCipher::modPermutationCipher(const std::wstring& skey) {
if (skey.empty()) {
throw std::invalid_argument("Ошибка: ключ не может быть пустым.
Пожалуйста, введите положительное целое число.");
}
alphabet =
L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯABCDEFGHIJKLMNOPQRSTUVWXYZ"; //
поддержка русского и английского алфавитов
validateKey(skey);
for (auto& ch : skey) {
key.push_back(wchar_t(ch) - L'0');
}
}
/*!
* \brief Валидация ключа.
*
* Функция проверяет, состоит ли ключ только из цифр и является ли он
положительным числом.
* Если ключ не удовлетворяет этим условиям, генерируется исключение.
*
* \param skey Строка, представляющая ключ.
* \throws std::invalid_argument Если ключ некорректен.
*/
void modPermutationCipher::validateKey(const std::wstring& skey) {
for (const auto& ch : skey) {
if (!iswdigit(ch)) {
throw std::invalid_argument("Ошибка: ключ должен состоять
только из цифр. Пожалуйста, введите положительное целое число.");
}
}
// Проверка на нулевой или отрицательный ключ
int keyValue = std::stoi(skey);
if (keyValue <= 0) {
throw std::invalid_argument("Ошибка: ключ должен быть
положительным целым числом. Пожалуйста, введите корректный ключ.");
}
}
/*!
* \brief Валидация текста.
*
* Функция проверяет, что текст не пустой и состоит только из символов,
которые присутствуют в алфавите.
* Если текст содержит недопустимые символы или пуст, генерируется
исключение.
*
* \param text Строка, представляющая текст для шифрования или
расшифровки.
* \throws std::invalid_argument Если текст пустой или содержит
недопустимые символы.
*/
void modPermutationCipher::validateText(const std::wstring& text) {
if (text.empty()) {
throw std::invalid_argument("Ошибка: текст не может быть пустым.
Пожалуйста, введите текст для шифрования/расшифрования.");
}
for (const auto& ch : text) {
if (alphabet.find(ch) == std::wstring::npos) {
throw std::invalid_argument("Ошибка: текст должен содержать
только буквы из заданного алфавита (русские и английские буквы).");
}
}
}
/*!
* \brief Шифрование текста.
*
* Функция шифрует текст с использованием перестановок на основе ключа.
Каждый символ текста сдвигается на значение,
* соответствующее текущему элементу ключа.
*
* \param open_text Строка, представляющая открытый текст.
* \return Зашифрованный текст.
* \throws std::invalid_argument Если текст не прошел валидацию.
*/
std::wstring modPermutationCipher::encrypt(const std::wstring& open_text)
{
validateText(open_text);
std::wstring result;
int keySize = key.size();
for (size_t i = 0; i < open_text.size(); ++i) {
int shift = key[i % keySize];
wchar_t ch = open_text[i];
std::size_t index = alphabet.find(ch); // Измените тип index на
std::size_t
if (index != std::wstring::npos) {
result.push_back(alphabet[(index + shift) % alphabet.size()]);
}
}
return result;
}
/*!
* \brief Расшифрование текста.
*
* Функция расшифровывает текст с использованием перестановок на основе
ключа. Каждый символ текста сдвигается на значение,
* соответствующее текущему элементу ключа, в обратном направлении.
*
* \param cipher_text Строка, представляющая зашифрованный текст.
* \return Расшифрованный текст.
* \throws std::invalid_argument Если текст не прошел валидацию.
*/
std::wstring modPermutationCipher::decrypt(const std::wstring&
cipher_text) {
validateText(cipher_text);
std::wstring result;
int keySize = key.size();
for (size_t i = 0; i < cipher_text.size(); ++i) {
int shift = key[i % keySize];
wchar_t ch = cipher_text[i];
std::size_t index = alphabet.find(ch); // Измените тип index на
std::size_t
if (index != std::wstring::npos) {
result.push_back(alphabet[(index - shift + alphabet.size()) %
alphabet.size()]);
}
}
return result;
}

#include "modGronsfeld.h"
/*!
* \brief Конструктор класса modAlphaCipher.
* \param skey Строка, представляющая ключ для шифрования.
* \throws std::invalid_argument Если ключ пустой или содержит
недопустимые символы.
*/
modAlphaCipher::modAlphaCipher(const std::wstring& skey) {
if (skey.empty()) {
throw std::invalid_argument("Key cannot be empty");
}
for (unsigned i = 0; i < numAlpha.size(); i++) {
alphaNum[numAlpha[i]] = i;
}
key = convert(skey);
}
/*!
* \brief Преобразует строку в вектор чисел.
* \param s Строка для преобразования.
* \return Вектор целых чисел.
* \throws std::invalid_argument Если строка содержит недопустимые
символы.
*/
std::vector<int> modAlphaCipher::convert(const std::wstring& s) {
std::vector<int> result;
for (auto c : s) {
if (alphaNum.find(c) == alphaNum.end()) {
throw std::invalid_argument("Invalid character in key.");
}
result.push_back(alphaNum[c]);
}
return result;
}
/*!
* \brief Преобразует числовой вектор в строку.
* \param v Вектор чисел.
* \return Строка символов.
* \throws std::invalid_argument Если индекс выходит за пределы алфавита.
*/
std::wstring modAlphaCipher::convert(const std::vector<int>& v) {
std::wstring result;
for (size_t i = 0; i < v.size(); ++i) {
if (static_cast<size_t>(v[i]) >= numAlpha.size()) {
throw std::invalid_argument("Index out of bounds");
}
result += numAlpha[v[i]];
}
return result;
}
/*!
* \brief Шифрует текст с использованием шифра Гронсфельда.
* \param open_text Текст для шифрования.
* \return Зашифрованный текст.
* \throws std::invalid_argument Если текст пустой или содержит
недопустимые символы.
*/
std::wstring modAlphaCipher::encrypt(const std::wstring& open_text) {
if (open_text.empty()) {
throw std::invalid_argument("Text cannot be empty");
}
try {
std::vector<int> work = convert(open_text);
for (unsigned i = 0; i < work.size(); i++) {
work[i] = (work[i] + key[i % key.size()]) % numAlpha.size();
}
return convert(work);
} catch (const std::exception& e) {
std::wcerr << L"Encryption error: " << e.what() << std::endl;
throw;
}
}
/*!
* \brief Расшифровывает текст с использованием шифра Гронсфельда.
* \param cipher_text Текст для расшифровки.
* \return Расшифрованный текст.
* \throws std::invalid_argument Если текст пустой или содержит
недопустимые символы.
*/
std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text) {
if (cipher_text.empty()) {
throw std::invalid_argument("Text cannot be empty");
}
try {
std::vector<int> work = convert(cipher_text);
for (unsigned i = 0; i < work.size(); i++) {
work[i] = (work[i] - key[i % key.size()] + numAlpha.size()) %
numAlpha.size();
}
return convert(work);
} catch (const std::exception& e) {
std::wcerr << L"Decryption error: " << e.what() << std::endl;
throw;
}
}

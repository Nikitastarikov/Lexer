# Lexer
1. Задание выполнено в приложении Visual Studio. В качестве входных параметров указываются файлы с программой, написанной на С#,
в проекте три таких файла, по умолчанию один файл уже вписан в программу, так что для запуска требуется просто скачать и запустить,
по желанию можно поменять входной файл.
2. Unit Tests сделаны для основных функций, которые учавствуют в формировании Токенов.
3. Программа считывает файл и построчно отправляет в функцию GetNextToken, которая является членом класса Lexer, 
в функции происходит считывание, в зависимости от типа строкового литерала происходит формирование Токена.
Считывание происходит пока файл не закончится. В данной версии программы все токены будут выводится на экран.

## Итоговый проект по Блоку «Основные конструкции C++»

####
* Список участников команды: Сутуленко Евгений
* Описание выбранной идеи решения :
##### 
Идея в том, что будет работать автомат состояний который следит за тем, что войден ли пользователь в чат или нет. И в зависимости от этого будут вариации алгоритма.
Вначале человеку предлагается создать нового пользователя или войти под существующим логином. После создания пользователя, можно войти в чат введя логин и пароль. Если
поля совпадают пользователь переходит в другое меню, где может написать сообщение кому-то, прочитать свои сообщения, или сменить пользователя и вернуться в предыдущее меню.
####
* описание пользовательских типов и функций в проекте:
##### 
В проекте 4 класса: 
* Array, представляет собой шаблонный контейнер
* User, который хранит логин, пароль, имя и сообщения
* Display, в котором находятся выводы некоторых сообщений для пользователя, и методы обрабатывания ввода пользователя
* Chat, который взаимодействует с остальными классами, и в котором исполняется автомат состояний 

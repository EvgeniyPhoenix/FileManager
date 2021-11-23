# FileManager

## Содержание
1. [Введение](#1)
1. [Требования пользователя](#2)  
    2.1. [Программные интерфейсы](#2.1)  
    2.2. [Интерфейс пользователя](#2.2)  
    2.3. [Характеристики пользователей](#2.3)
1. [Системные требования](#3)  
    3.1. [Функциональные требования](#3.1)  
    3.2. [Нефункциональные требования](#3.2)     
    3.3. [Ограничения](#3.3)  
 1. [Аналоги](#4)
--- 
## 1. Введение <a name="1"></a>
File Manager - это десктоп приложение, которое предоставляет доступ к файлам и каталогам системы при помощи двух панелей навигации.
Двухпанельная навигация облегчает проведение операций с файлами и каталогами, позволяет копировать и перемещать их из одной панели в другую.  

## 2. Требования <a name="2"></a>
### 2.1. Программные интерфейсы <a name="2.1"></a>
Приложение разработано на языке C++.
Данные пользователей хранятся в базе данных Microsoft Access.
Приложение предоставляет удобный графический интерфейс, разработанный при помощи кроссплатформенного фреймворка Qt Creator.

### 2.2. Интерфейс пользователя <a name="2.2"></a>
[Окно аутентификации](https://github.com/EvgeniyPhoenix/FileManager/tree/main/pics/login.png) представляет окно аутентификации пользователей для работы с приложением. Данное окно содержит поля для ввода логина и пароля, а так же выводит информацию о состоянни базы данных пользователей и успешности аутентификации.  
[Основное окно](https://github.com/EvgeniyPhoenix/FileManager/tree/main/pics/main.png) предоставляет доступ к навигации в файловой системе посредством двух панелей. Так же доступны действия с файлами и каталогами, такие как: создание каталогов, изменение имени, копирование, перемещение и удаление файлов и каталогов.  
[Информационное окно](https://github.com/EvgeniyPhoenix/FileManager/tree/main/pics/info.png) предоставляет общую информацию о приложении и его разработчике.

### 2.3. Характеристики пользователей <a name="2.3"></a>
Приложение предназначено для пользователей, которым необходим более быстрый и удобный способ работы с файлами и каталогами, чем предлагаемый стандартным проводником операционной системы Windows.

| Класс пользователей | Описание |
|---|---|
| **Admin** | Пользователь, являющийся управляющим всего приложения. Имеет доступ к полному функционалу. Имеет возможность создания/удаления пользователей. |
| **User** | Пользователь, который имеет доступ только к просмотру содержимого файлов и каталогов. Данный пользователь не имеет доступа к созданию/удалению других пользователей. |

## 3. Системные требования <a name="3"></a>
Работа приложения осуществляется на операционных системах семейства Windows.

### 3.1. Функциональные требования <a name="3.1"></a>
Пользователю предоставлены возможности:
1. Аутентификация (регистрация и вход);
1. Двухпанельная навигация по файловой системе;
1. Создание и удаление файлов и каталогов;
1. Работа с файлами и каталогами.

### 3.2 Нефункциональные требования <a name="3.2"></a>
1. Простой и удобной графический интерфейс приложения.
2. Независимость от доступа к сети "Интернет".
3. Приложение разработано на языка C++.
4. Приложение использует базы данных Microsoft Access.

### 3.3 Ограничения <a name="3.3"></a>
1. Операционные системы семейства Windows.
2. Устройства с поддержкой платформ х86 и x64.
3. Наличие прав администратора на устройстве, для установки приложения.

## 4. Аналоги <a name="4"></a>
1. Total Commander - приложение, разработанное Кристианом Гизлером в 1993 году на языках Object Pascal И Delphi.
2. Far Manager - приложение, разработанное Евгением Рошалом в 1996 году, также на языке C++.

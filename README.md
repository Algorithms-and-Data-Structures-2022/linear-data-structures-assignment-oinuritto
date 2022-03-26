# C++ auto-graded assignment template

[![Build Status](../../actions/workflows/classroom.yml/badge.svg)](../../actions/workflows/classroom.yml)
![Points bar](../../blob/badges/.github/badges/points-bar.svg)

## 1. Информация о студенте

**Номер группы**: 11-101

**Фамилия и Имя**: Сабитов Айнур

## 2. Описание задания

Вам необходимо реализовать функционал 4 линейных структур данных:
1. Динамический массив - [_src/dynamic_array.cpp_](src/dynamic_array.cpp)
2. Связный список (односвязный) - [_src/linked_list.cpp_](src/linked_list.cpp)
3. Стек (на базе динамического массива) - [_src/array_stack.cpp_](src/array_stack.cpp)
4. Очередь (на базе односвязного списка) - [_src/linked_queue.cpp_](src/linked_queue.cpp)

**Внимательно изучите документацию ко всем реализуемым методам (см. [заголовочные файлы](include/assignment)).**

Файл [_src/node.cpp_](src/node.cpp) **НЕЛЬЗЯ МОДИФИЦИРОВАТЬ**! 

## 3. Инструкции

1. Склонируйте локальную копию репозитория к себе на компьютер.
2. Внесите информацию о себе в раздел "Информация о студенте".
3. Подробно изучите описание задания. При наличии вопросов обратитесь к <strike>врачу</strike> преподавателю.
4. Реализуйте задание в соответствии указанным требованиям.
5. Запустите локальные тесты (при их наличии).
6. Отправьте задание на auto-grading тесты и дождитесь итогового балла.
7. Повторите пункты 4-6 до получения макс. кол-ва баллов.

## 4. Ограничения

- Запрещается вносить изменения в файлы, не указанных в разделе "Описание задания".
- Запуск auto-grading тестов осуществляется:
  - автоматически при внесении изменений в [_src_](src) и/или [_include_](include)
  на ветках _**master**_ или _**main**_;
  - вручную во вкладке _Actions_.

## 5. Примечания

- Результирующие баллы высчитываются при каждом новом push'е (для последнего commit'а).
- По истечении установленных временных сроков сдачи система продолжит высчитывать итоговый балл при внесении изменений.
- Сроки сдачи устанавливаются преподавателем и указываются в индивидуальном порядке для каждой группы.
- Тесты подразделяются на **локальные** и **auto-grading**:
  - локальные тесты запускаются на компьютере через среду разработки (IDE);
  - auto-grading тесты запускаются на GitHub и вычисляют итоговый балл за задание.
- При клонировании репозитория через терминал используйте команду: 
  ```shell
    git clone --recurse-submodules <URL>
  ```

---

**Преподаватель**: Рамиль Сафин (Telegram: [_@safin_ramil_](https://t.me/safin_ramil), e-mail: _safin.ramil@it.kfu.ru_).

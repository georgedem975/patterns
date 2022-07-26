# GRASP

---

### Что это такое?

__GRASP__ - это шаблоны, используемые в объектно-ориентированном проектировании для решения общих задач по назначению ответственностей классам и объектам.В книге Крэга Лармана «___Применение UML и шаблонов проектирования___» описано 9 таких шаблонов: каждый помогает решить некоторую проблему, возникающую как в объектно-ориентированном анализе, так и в практически любом проекте по разработке программного обеспечения.

---

### Перечень шаблонов:
##### 1. Информационный эксперт (Information Expert)
Шаблон определяет базовый принцип распределения ответственностей: ___Ответственность должна быть назначена тому, кто владеет максимумом необходимой информации для исполнения — информационному эксперту.___
<br>
Локализация же ответственностей, проводимая согласно шаблону:
+   Повышает:
    *    Инкапсуляцию;
    *    Простоту восприятия;
    *    Готовность компонентов к повторному использованию;
+   Снижает:
    *    степень зацепления.

##### 2. Создатель (Creator)
Класс должен создавать экземпляры тех классов, которые он может:
+   Содержать или агрегировать;
+   Записывать;
+   Использовать;
+   Инициализировать, имея нужные данные.

##### 3. Контроллер (Controller)
* Отвечает за операции, запросы на которые приходят от пользователя, и может выполнять сценарии одного или нескольких вариантов использования (например, создание и удаление);
* Не выполняет работу самостоятельно, а делегирует компетентным исполнителям;
* Может представлять собой:
    + Систему в целом;
    + Подсистему;
    + Корневой объект;
    + Устройство.

##### 4. Слабое зацепление (Low Coupling)
«___Степень зацепления___» — мера неотрывности элемента от других элементов (либо мера данных, имеющихся у него о них).
<br>__«Слабое» зацепление__ является оценочной моделью, которая диктует, как распределить обязанности, которые необходимо поддерживать.
<br>__«Слабое» зацепление__ — распределение ответственностей и данных, обеспечивающее взаимную независимость классов. Класс со «слабым» зацеплением:
+   Имеет слабую зависимость от других классов;
+   Не зависит от внешних изменений (изменение в одном классе оказывает слабое влияние на другие классы);
+   Прост для повторного использования.

##### 5. Высокая связность (High Cohesion)
__Высокая связность класса__ — это оценочная модель, направленная на удержание объектов должным образом сфокусированными, управляемыми и понятными. Высокая связность обычно используется для поддержания низкого зацепления. Высокая связность означает, что обязанности данного элемента тесно связаны и сфокусированы. Разбиение программ на классы и подсистемы является примером деятельности, которая увеличивает связность системы.
И наоборот, __низкая связность__ — это ситуация, при которой данный элемент имеет слишком много несвязанных обязанностей. Элементы с низкой связностью часто страдают от того, что их трудно понять, трудно использовать, трудно поддерживать.

##### 6. Полиморфизм (Polymorphism)
Устройство и поведение системы:
+ Определяется данными;
+ Задано полиморфными операциями её интерфейса.

##### 7. Чистое изготовление (Pure Fabrication)
Не относится к предметной области, но:
+ Уменьшает зацепление;
+ Повышает связность;
+ Упрощает повторное использование.

##### 8. Перенаправление (Indirection)
Слабое зацепление между элементами системы (и возможность повторного использования) обеспечивается назначением промежуточного объекта их посредником.

##### 9. Устойчивость к изменениям (Protected Variations)
Шаблон защищает элементы от изменения другими элементами (объектами или подсистемами) с помощью вынесения взаимодействия в фиксированный интерфейс, через который (и только через который) возможно взаимодействие между элементами. Поведение может варьироваться лишь через создание другой реализации интерфейса.
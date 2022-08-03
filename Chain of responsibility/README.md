### Chain of responsibility. ⛓
---
Цепочка Обязанностей (Chain of responsibility) - поведенческий шаблон проектирования, который позволяет избежать жесткой привязки отправителя запроса к получателю. Все возможные обработчики запроса образуют цепочку, а сам запрос перемещается по этой цепочке. Каждый объект в этой цепочке при получении запроса выбирает, либо закончить обработку запроса, либо передать запрос на обработку следующему по цепочке объекту.
![Patterns](https://github.com/georgedem975/georgedem975/blob/master/assets/relationships%20between%20classes.png)
![Chain of resposibility](https://github.com/georgedem975/georgedem975/blob/master/assets/chain%20of%20responsibility.jpg)

---

#### поллезные ссылки:
+ [Chain of responsibility](https://habr.com/ru/post/113995/)
+ [Chain of responsibility](https://ru.wikipedia.org/wiki/Цепочка_обязанностей)
+ [Chain of responsibility](https://metanit.com/sharp/patterns/3.7.php)
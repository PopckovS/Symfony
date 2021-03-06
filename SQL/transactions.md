## Транзакции в SQL
Транзакции - это механизм который копирует таблицы учавствующие в
работе и их связи, в отдельную виртуальную область памяти, после 
чего происходит обработка SQL запроса над этими таблицами, в случае
есил транзакция выполняется успешно, то все теже SQL операции 
применяются с реальными таблицами на жестком диске, уже без оперативной
памяти. В случае неудачи запрос не будет выполнен вовсе, таким образом
в случае если в запросе есть ошибка, или другая проблема непозволяющая
сдлеать SQL инструкцию, это не повредит самой Базе Данных.

Синтаксис транзакций зависит от СУБД.

Транзакция - набор инструкций SQL.
Откат - процесс отмены указаннызинструкций SQL.
Фиксация - Запись в таблицы БД.
Точка сохранения - временное состояние в ходе выполнения транзакции,
в которое можно вернуться после отмены части набора SQL инструкций.
То есть не отменять всю транзакцию а только до последней точки остановки.

Транзакции применимы к операциям типа INSERT, UPDATE, DELETE,
CREATE, DROP.

Суть работы с транзакциями в том чтобы, сформировать из SQL отдельные
блоки и в явном виде указывать где делать откаты.


### ROLLBACK
ставив такую строку в операцию удаления, мы тем самым откатываем 
удаления всего из таблицы.

    DELETE FROM Orders;
    ROLLBACK;

### COMMIT 
Ключевое слово COMMIT указывает необходимость зафиксировать изменения
в реальной БД.

    BEGIN TRANSACTION
    DELETE OrderItems WHERE order_num = 12345
    DELETE Orders WHERE order_num = 12345
    COMMIT TRANSACTION

Эта инструкция начинает транзакцию с `BEGIN TRANSACTION` далее 
удаляет из обоих таблиц записи с `order_num = 12345` и только после
этого командой `COMMIT TRANSACTION` закрепляется в реально таблице.

Если первое удаление произойдет, а второе нет, такая инструкция может
быть не безопасна, ибо одна запись удалена а другая нет, чтобы такого 
небыло, и используются транзакции, будут удалены обе записи или ни одна.

`COMMIT` и `ROLLBACK` применяются для сохранения или удлаения всей 
транзакции, это применимо для коротких SQL инструкций, но в случае если
транзакция длинная то нам потребуется сохранять транзакцию частично.

### Точки сохранения. SAVEPOINT
В зависимости от СУБД точки сохранения имеют разный синтаксис.

    SAVEPOINT point1

    или

    SAVE TRANSACTION point1

Каждая точка сохранения должна обладать уникальным имененм.

Для отмены всех инструкций идущих после точки сохранения следует
выполнить команду:

    ROLLBACK TRANSACTION point1;

Запишим один из таких примеров:

    BEGIN TRANSACTION 
        INSERT INTO ...
    SAVE TRANSACTION point1;
        INSERT INTO ...
    SAVE TRANSACTION point2;
        IF @@ERROR <> 0 ROLLBACK TRANSACTION point1;
    COMMIT TRANSACTION

Благодаря специальному синтаксису мы можем обрабатывать условия IF
прямо в самом запрсое, и тут же решать стоит ли откатывать до точки 
сохранения или же вовсе откатить всю транзакцию.












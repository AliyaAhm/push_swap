# push_test

Простой тестер для пушсвапа, показывает лучший/худший/средний результат из заданого числа итераций и ошибки.

## Установка

Закинуть все файлы в любую папку, так же требуется наличие python 3.


## Запуск

```bash
./push_test.sh <пушсвап> <чекер> <кол-во чисел> <кол-во итераций>
```
Примеры:
```bash
./push_test.sh ./push_swap ./checker_linux 100 1000
```
```bash
./push_test.sh ./push_swap ./checker 5 100
```

Тестирование можно прервать с помощью <kbd>Ctrl</kbd> + <kbd>C</kbd> и увидеть промежуточный результат.
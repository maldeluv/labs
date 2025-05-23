data segment ; директива начала сегмента данных
count dw ?
mass db -1,0,2,3,-8,6,-7,-6,9,4 ; массив из 10 элементов, каждый размером в байт
data ends
code segment ; директива начала сегмента кодов
assume cs: code, ds: data ; установка соответсвий сегментов и их адресов
start: ; метка входа
mov ax,data ; Загрузка адреса
mov ds,ax ; сегмента данных
lea bx,mass ; Загружаем в bx адрес массива
mov cx,10 ; Установить счетчик повторений цикла
mov ax,0
beg:cmp byte ptr[bx],0 ; Сравниваем однобайтовое значение по адресу, лежащему в bx, с нулем
jle no ; если <= 0 то переходим к метке no
inc ax ; если >0, то увеличиваем количество на единицу
no: 
inc bx ; переход к следующему элементу массива
loop beg ; повтор, пока cx не станет равным нулю
mov count, ax ; результат записывается в count
quit:				; метка выхода
	mov ax, 4c00h 	; код завершения: 0
	int 21h 		; выход в DOS
code ends
end start
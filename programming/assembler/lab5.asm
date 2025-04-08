data segment ; директива начала сегмента данных
msg1    DB  "Введите строку: $"
msg2    DB  0Ah, 0Dh, "Введите шаблон: $"
msg3    DB  0Ah, 0Dh, "Да!$"
msg4    DB  0Ah, 0Dh, "Нет$"
 
str1ml  DB  200
str1l   DB  '$'
str1    DB  200 dup('$')
 
str2ml  DB  200
str2l   DB  '$'
str2    DB  200 dup('$')
data ends 
code segment ; директива начала сегмента кодов
assume cs: code, ds: data ; установка соответсвий сегментов и их адресов
start:
    mov ax, data
    mov ds, ax
    mov es,ax
    xor ax,ax

    lea dx, msg1    ;вывод msg1
    call    strout
 
    lea dx, str1ml  ;ввод строки str1
    call    strin
 
    lea dx, msg2    ;вывод msg2
    call    strout
 
    lea dx, str2ml  ;ввод строки str2
    call    strin
 
    xor cx, cx
    mov cl, str1l   ;устанавливается кол-во повторений
    sub cl, str2l
    inc cl
    cld         ;Сбросить флаг направления
    lea di, str2    ;в di - строка, которую надо найти
    lea si, str1    ;в si - строка, в которой ищем
    xor ax, ax
 
beg:         ;повторяется для str1 до конца строки минус длина str2
    
    push    cx
    push    di
    push    si
    mov bx, si
    mov cl, str2l

compare_strings:
    mov al, [si]          ; Считываем байт из строки source
    mov bl, [di]          ; Считываем байт из строки destination
    cmp al, bl             ; Сравниваем байты
    jne _neq          ; Если не равны, переход

    ; Если байты равны:
    inc si                ; Переходим к следующему байту строки source
    inc di                ; Переходим к следующему байту строки destination
    loop compare_strings   ; Уменьшаем CX и повторяем, если CX > 0
    jmp _eq              ; Все байты равны

_eq:
    lea dx, msg3    ;вывод msg1
    call    strout
    jmp _end
_neq:
    pop si
    pop di
    pop cx
 
    inc si
loop    beg
    
    lea dx, msg4
    call    strout
 
_end:
    mov     ah, 4ch    
    int 21h
 
 
;*****************Процедуры***********************
 
;*************************************************
strin   proc
    mov ah, 0Ah
    int 21h
    ret
strin   endp
;*************************************************
strout  proc
    mov ah, 09h
    int 21h
    ret
strout  endp
;*************************************************
code ends
end start

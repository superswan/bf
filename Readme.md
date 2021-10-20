# BrainF***

Having some fun with bf

**bf -** simple interpreter that takes input from files. variable tape size.

**ascii2bf -** converts ascii text into a bf program

```
example:
    File 'helloworld' contains string "Hello, World!"
    $ ascii2bf "$(cat helloworld)"
    >--->--->--->++>+>--->->--->->>-->->->->->+++>-->->>++>-->+>+>--->->+++>--->+++>-->->>-->->>-->->>--->->->>-->+[<+++[-<+++++++>]<+++[-<+++++++>]<+++[.>]<]
    $ ascii2bf "$(cat helloworld)" > helloworld.bf
    $ bf -f helloworld.bf
    Hello, World!
```
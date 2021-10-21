# BrainF***

Having some fun with bf

**bf -** simple interpreter that takes input from files. variable tape size.

**ascii2bf -** converts ascii text into a bf program

**bfloader -** Loads hex escaped shellcode ("\xaa\xff") converted to bf program

**[WIP] bfexec -** Executes bf encoded shell commands

```
example:
    // ascii2bf and bf interpreter
    File 'helloworld' contains string "Hello, World!"
    $ ascii2bf "$(cat helloworld)"
    >--->--->--->++>+>--->->--->->>-->->->->->+++>-->->>++>-->+>+>--->->+++>--->+++>-->->>-->->>-->->>--->->->>-->+[<+++[-<+++++++>]<+++[-<+++++++>]<+++[.>]<]
    $ ascii2bf "$(cat helloworld)" > helloworld.bf
    $ bf -f helloworld.bf
    Hello, World!
```

## Screenshots
![bfloader](https://pomf2.lain.la/f/dti3twvf.png)
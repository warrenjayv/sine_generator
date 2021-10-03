
# sine_generator
A simple sine generator that output a textfile  for plotter...

# installation
  1. clone to your desired directory
  2. open terminal, type & enter `gcc sine_generator.c`

# utilization
    :: NOTE: used in CYGWIN, two terminals, one for X Server; two for compile, execute, and plot 

  1. open terminal, type `./a.exe <number of samples> <number of cycles>`
  
    :: WARNING: parameters must be enclosed via strings...

     `./a.exe "1024" "6" "0"`
  2. type and run `gnuplot`
  3. type & enter `set terminal png`
  4. type & enter `set output "out.png`
  5. type & enter `plot "sine_wave.txt" with lines`

![image](https://user-images.githubusercontent.com/40836157/135745211-7e3684a3-7837-4077-bbef-6fe0d2448132.png)

#!/usr/bin/python

# How to use
# Input = [ 'input line for test case 1', 'input line for test case 2', ... ]
# Output = [ 'output line for test case 1', 'output line for test case 2', ... ]
# Now only support single-line input and output.

# prac7
Input = [ '1 3 5 4 -5 100 7777 2014 0',
        '1 3 5 4 -5 100 7777 2014',
        '-5 -8 -4 -2 -1',
        ]
Output = [ 'true -5 0 1 3 4 5 100 2014 7777',
        'false -5 1 3 4 5 100 2014 7777',
        'false -8 -5 -4 -2 -1',
        ]

def silent_remove(filename):
    try:
        os.remove(filename)
    except OSError:
        pass

def tidyup(string):
    return ' '.join(string.split())

import os

silent_remove('main.out')

assert os.path.isfile('main.cpp'), 'main.cpp does not exist'

os.system('g++ -o main.out -O2 -Wall *.cpp')
assert os.path.isfile('main.out'), 'does not compile'

correct = 0

for input_str, output_str in zip(Input, Output):
    input_str = tidyup(input_str)
    output_str = tidyup(output_str)

    silent_remove('tempinput.adds')
    silent_remove('tempoutput.adds')

    with open('tempinput.adds','w') as fp:
        fp.write(input_str)
    assert os.path.isfile('tempinput.adds'), 'fail to create tempinput'

    os.system('./main.out < tempinput.adds > tempoutput.adds')
    assert os.path.isfile('tempoutput.adds'), 'fail to create tempoutput'

    obtained_str = 'Your output is empty'
    with open('tempoutput.adds') as fp:
        for line in fp:
            obtained_str = tidyup(line)
            break
        
    print 'input: ',input_str
    print 'expecting: ',output_str
    print 'obtained : ',obtained_str
    if obtained_str == output_str:
        print 'correct'
        correct += 1
    else:
        print 'wrong'

    print ''

print 'Test result: ', correct, '/', len(Input)
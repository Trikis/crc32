from itertools import islice
from invRegex import invert
import optparse 
import os


def get_arguments():
    parse = optparse.OptionParser()
    parse.add_option("-r" , "--reg" , dest = "reg" , help = "Input there regex expression")
    parse.add_option("-n" , "--num" , dest = "num" , help = "Number of passwords")
    arguments = parse.parse_args()[0]
    if not arguments.reg:
        parse.error("Your input is shit")
    elif not arguments.num:
        parse.error("Your input is shit")
    return arguments.reg , arguments.num


regex , num  = get_arguments()
num = int(num)

path = os.path.join('Passwords' , 'tmp_regex.txt')
with open(path , 'w') as file:
    file.write("\n".join(islice(invert(regex), num)))
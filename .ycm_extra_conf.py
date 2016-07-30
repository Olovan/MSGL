import os
import ycm_core

flags = [
        '-I./include',
        '-I./src',
        '-I/usr/local/include',
        '-lglfw',
        '-lGL',
        '-std=c++11',
        '-x', 'c++',
        ]

def ConvertPaths():
    retval = [] 
    for flag in flags:
        if (flag.startswith('-I./') or flag.startswith('-L./')):
            flag = flag[0:2] + DirectoryOfThisScript() + flag[3:]
        retval.append(flag)
    return retval


def DirectoryOfThisScript():
      return os.path.dirname( os.path.abspath( __file__ ) )

def FlagsForFile(arg):
    abs_flags = ConvertPaths();

    return {
    'flags': abs_flags,
    'do_cache': True
    }

#print(ConvertPaths()); #DEBUG

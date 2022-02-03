from distutils.core import setup, Extension
from os import getcwd
import platform

cwd = getcwd()

ela = ''
if platform.system() == 'Darwin' in platform.node():
    ela = '-Wl,-rpath,'+cwd+'../../library'

module = Extension('CO2AR',
                    define_macros = [('MAJOR_VERSION', '1'),
                                     ('MINOR_VERSION', '0')],
                    include_dirs = [cwd+'/../../library'],
                    libraries = ['mbCO2AR'],
                    library_dirs = [cwd+'/../../library'],
                    runtime_library_dirs = [cwd+'/../../library'],
                    extra_link_args = [ela],
                    sources = ['mbCO2AR.cpp'])
setup (name = 'CO2AR',
       version = '1.0',
       author = 'Olaseni Sode',
       author_email = 'osode@calstatela.edu',
       ext_modules = [module])

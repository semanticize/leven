from distutils.core import setup, Extension

setup(
    name='leven',
    version='1.0.2',
    description='Levenshtein edit distance library',
    maintainer='Lars Buitinck',
    maintainer_email='l.j.buitinck@esciencecenter.nl',
    packages=['leven'],
    ext_modules=[
        Extension("leven._levensthein", ["leven/_levenshtein.cpp"])
    ],
    install_requires=["six", "nose"],
    url='https://github.com/semanticize/leven',
)

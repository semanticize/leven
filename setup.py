from setuptools import setup, Extension

setup(
    name='leven',
    version='1.0.4',
    description='Levenshtein edit distance library',
    maintainer='Lars Buitinck',
    maintainer_email='l.j.buitinck@esciencecenter.nl',
    packages=['leven'],
    ext_modules=[
        Extension("leven._levenshtein", ["leven/_levenshtein.cpp"],
                  include_dirs=["leven"])
    ],
    install_requires=["six", "nose"],
    url='https://github.com/semanticize/leven',
    test_suite='nose.collector'
)

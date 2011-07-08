load('../test-common.js');

assert( matchesGlob('*.*', 'README.txt') );
assert( !matchesGlob('[a-z]*', 'README.txt') );
assert( matchesGlob('[A-Z]*', 'README.txt') );
assert( !matchesLike('A%', 'README.txt') );
assert( matchesLike('R%', 'README.txt') );
assert( !matchesLike('r%', 'README.txt') );
assert( matchesLike('r%', 'README.txt', false) );

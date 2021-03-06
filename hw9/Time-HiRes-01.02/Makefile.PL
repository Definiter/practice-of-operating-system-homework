use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    'NAME'	=> 'Time::HiRes',
    'VERSION_FROM' => 'HiRes.pm', # finds $VERSION
    'LIBS'	=> [''],   # e.g., '-lm' 
    'DEFINE'	=> '',     # e.g., '-DHAVE_SOMETHING' 
    'XSPROTOARG'	=> '-noprototypes', 
    'INC'	=> '',     # e.g., '-I/usr/include/other' 
    'dist'      => {
	'CI'=>'ci -l',
	'COMPRESS'=>'gzip -9f', 
	'SUFFIX' => 'gz',
	}
);

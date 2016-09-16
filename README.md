# NAME

Hash::BulkKeyCopy - a xs module for clone hash with keys

# SYNOPSIS

    use Hash::BulkKeyCopy;

# USAGE

my $ht\_ka = \["k1\_1", "k1\_2", "k1\_3"\]; # it will use src\_hash's keys when give an empty array  
my $hs\_ka = \["k2\_1", "k2\_2", "k2\_3"\];  

my ($h1, $h2) = ({}, {"k2\_1" => 1, "k2\_2" => undef, "k2\_3" => \[\]});  
hash\_bulk\_keycopy($h1, $h2, $ht\_ka, $hs\_ka);  

# DESCRIPTION

Hash::BulkKeyCopy is a xs module for clone hash by a key arr.  
Double faster than PP source.

# LICENSE

Copyright (C) itsusony. FreakOut.

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself.

# AUTHOR

itsusony <itsusony@fout.jp>

package Hash::BulkKeyCopy;
use 5.008001;
use strict;
use warnings;
use Exporter 'import';

our $VERSION = "0.01";

our @EXPORT_OK = qw/hash_bulk_keycopy/;

use XSLoader;
XSLoader::load(__PACKAGE__, $VERSION);

1;
__END__

=encoding utf-8

=head1 NAME

Hash::BulkKeyCopy - a xs module for clone hash with keys

=head1 SYNOPSIS

    use Hash::BulkKeyCopy;

=head1 DESCRIPTION

Hash::BulkKeyCopy is a xs module for clone hash by a key arr.
Double faster than PP source.

=head1 LICENSE

Copyright (C) itsusony.

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself.

=head1 AUTHOR

itsusony E<lt>itsusony@fout.jpE<gt>

=cut


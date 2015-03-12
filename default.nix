let
  pkgs = import <nixpkgs> {};
  inherit (pkgs) stdenv lib libtermkey pkgconfig;

in

stdenv.mkDerivation {
  name = "test";
  src = ./.;
  buildInputs = [ libtermkey pkgconfig ];
  buildPhase = ''
    exit 1
  '';
}

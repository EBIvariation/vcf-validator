{
  description = "VCF Validator - Validation suite for Variant Call Format (VCF) files";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        packages.default = pkgs.stdenv.mkDerivation rec {
          pname = "vcf-validator";
          version = "0.10.2";

          src = ./.;

          nativeBuildInputs = with pkgs; [
            cmake
            pkg-config
          ];

          buildInputs = with pkgs; [
            boost
            curl
            openssl
            zlib
            bzip2
          ];

          cmakeFlags = [
            "-DSTATIC_BUILD=OFF"
            "-DCMAKE_BUILD_TYPE=Release"
          ];

          enableParallelBuilding = true;

          installPhase = ''
            runHook preInstall
            
            mkdir -p $out/bin
            cp bin/vcf_validator $out/bin/
            cp bin/vcf_assembly_checker $out/bin/
            
            runHook postInstall
          '';

          doCheck = true;
          checkPhase = ''
            runHook preCheck
            ctest --output-on-failure
            runHook postCheck
          '';

          meta = with pkgs.lib; {
            description = "Validation suite for Variant Call Format (VCF) files";
            homepage = "https://github.com/EBIvariation/vcf-validator";
            license = licenses.asl20;
            maintainers = [ ];
            platforms = platforms.unix;
          };
        };

        apps.default = {
          type = "app";
          program = "${self.packages.${system}.default}/bin/vcf_validator";
        };

        apps.vcf_validator = {
          type = "app";
          program = "${self.packages.${system}.default}/bin/vcf_validator";
        };

        apps.vcf_assembly_checker = {
          type = "app";
          program = "${self.packages.${system}.default}/bin/vcf_assembly_checker";
        };

        devShells.default = pkgs.mkShell {
          inputsFrom = [ self.packages.${system}.default ];
          packages = with pkgs; [
            # Debugging tools
            gdb
            valgrind
            
            # Linters and static analysis
            clang-tools    # clang-tidy, clang-format
            cppcheck       # C++ static analyzer
            include-what-you-use  # Include optimization
            cpplint        # Google's C++ style checker
            
            # Build tools
            bear           # Generates compile_commands.json for clang tools
            ninja          # Faster builds
          ];
        };
      });
}
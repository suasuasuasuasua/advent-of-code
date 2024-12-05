{pkgs, ...}: {
  # https://devenv.sh/packages/
  packages = with pkgs; [
    git
    fastfetch
    btop
    bat
    yazi
  ];

  # https://devenv.sh/languages/
  languages.python = {
    enable = true;
    version = "3.11";
    poetry = {
      enable = true;
      activate.enable = true;
      install = {
        enable = true;
        extras = [];
        groups = ["dev"];
      };
    };
  };

  devcontainer = {
    enable = true;
    settings = {
      image = "ghcr.io/cachix/devenv:latest";
      customizations.vscode.extensions = [
        "mkhl.direnv"
        "ms-python.python"
      ];
    };
  };

  # https://devenv.sh/pre-commit-hooks/
  git-hooks.hooks = {
    # Nix
    alejandra.enable = true;
    deadnix.enable = true;

    # Git
    commitizen.enable = true;

    # Docs
    markdownlint.enable = true;

    # General
    check-merge-conflicts.enable = true;
    end-of-file-fixer.enable = true;
    trim-trailing-whitespace.enable = true;

    # Python
    poetry-check.enable = true;
    black.enable = true;
  };

  # See full reference at https://devenv.sh/reference/options/
}

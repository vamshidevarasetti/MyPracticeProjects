from setuptools import setup, find_packages

setup(
    name="change_impact_tool",
    version="1.0.0",
    author="vamshi devarasetty",
    install_requires=[
        "GitPython>=3.1"
    ],
    entry_points={
        "console_scripts": [
            "change_impact = change_impact.cli:main",
        ],
    },
    description="CLI tool to generate a Git Change Impact Summary",
    python_requires=">=3.6",
)
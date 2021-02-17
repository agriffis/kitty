#!/usr/bin/env python
# vim:fileencoding=utf-8
# License: GPLv3 Copyright: 2021, Kovid Goyal <kovid at kovidgoyal.net>


import os
import unittest


class TestBuild(unittest.TestCase):

    def test_exe(self) -> None:
        from kitty.constants import kitty_exe
        exe = kitty_exe()
        self.assertTrue(os.access(exe, os.X_OK))
        self.assertTrue(os.path.isfile(exe))
        self.assertIn('kitty', os.path.basename(exe))

    def test_loading_extensions(self) -> None:
        import kitty.fast_data_types as fdt
        from kittens.unicode_input import unicode_names
        from kittens.choose import subseq_matcher
        from kittens.diff import diff_speedup
        del fdt, unicode_names, subseq_matcher, diff_speedup

    def test_loading_shaders(self) -> None:
        from kitty.utils import load_shaders
        for name in 'cell border bgimage tint blit graphics'.split():
            load_shaders(name)

    def test_glfw_modules(self) -> None:
        from kitty.constants import is_macos, glfw_path
        modules = ('cocoa',) if is_macos else ('x11', 'wayland')
        for name in modules:
            path = glfw_path(name)
            self.assertTrue(os.path.isfile(path))
            self.assertTrue(os.access(path, os.X_OK))

    def test_all_kitten_names(self) -> None:
        from kittens.runner import all_kitten_names
        names = all_kitten_names()
        self.assertIn('diff', names)
        self.assertIn('hints', names)
        self.assertGreater(len(names), 8)


def main() -> None:
    tests = unittest.defaultTestLoader.loadTestsFromTestCase(TestBuild)
    r = unittest.TextTestRunner(verbosity=4)
    result = r.run(tests)
    if result.errors or result.failures:
        raise SystemExit(1)

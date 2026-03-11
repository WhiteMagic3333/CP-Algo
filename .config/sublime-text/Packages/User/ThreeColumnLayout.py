import sublime
import sublime_plugin

class ThreeColumnLayoutCommand(sublime_plugin.WindowCommand):
    def run(self):
        # Set the window layout to 3 columns
        self.window.set_layout({
            "cols": [0.0, 0.33, 0.66, 1.0],
            "rows": [0.0, 1.0],
            "cells": [
                [0, 0, 1, 1],
                [1, 0, 2, 1],
                [2, 0, 3, 1]
            ]
        })
        
        # Open the files in columns
        self.window.open_file("A.cpp")
        self.window.open_file("inputf.in")
        self.window.open_file("outputf.out")

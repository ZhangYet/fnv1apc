#codig=utf8

from fnv1a_relay import fnv1a_hashpos
import fnv1a
import unittest

class BasicTest(unittest.TestCase):

    def test_equality(self):
        metric = 'eru.log.test'
        self.assertEqual(fnv1a_hashpos(metric, len(metric)), fnv1a.fnv1a(metric, len(metric)))

if __name__ == '__main__':
    unittest.main()

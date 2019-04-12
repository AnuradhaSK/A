import tensorflow as tf

# Settings
flags = tf.app.flags
FLAGS = flags.FLAGS

#core params..
flags.DEFINE_string('model', 'gcn', 'model name')
flags.DEFINE_float('learning_rate', 0.01, 'initial learning rate')
flags.DEFINE_string("model_size", "small", "define model size")


def main(argv=None):
    print("Flags Set")
    print(FLAGS.learning_rate)
    print(FLAGS.model)

if __name__ == '__main__':
    tf.app.run()

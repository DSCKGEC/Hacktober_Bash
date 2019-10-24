const app = new Vue({
  el: '#app',
  data: {
    welcome_message: 'Welcome to Hacktoberfest Vuejs Code!',
    hover_message: 'You loaded this page on ' + new Date().toLocaleString(),
    seen: true,
    todos: [
      { text: 'Learn JavaScript' },
      { text: 'Learn Vue' },
      { text: 'Learn Swift' }
    ],
    rvsMessage: 'Vuejs Code',
    textInput: '- Type something '
  },
  methods: {
    hideText: function () {
      this.seen = !this.seen
    },
    reverseMessage: function () {
      this.rvsMessage = this.rvsMessage.split('').reverse().join('')
    }    
  }
})
